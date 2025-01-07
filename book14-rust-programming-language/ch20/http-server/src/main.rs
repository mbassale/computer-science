use anyhow::anyhow;
use anyhow::bail;
use anyhow::Result;
use std::fs;
use std::io::BufRead;
use std::io::BufReader;
use std::io::Write;
use std::net::IpAddr;
use std::net::Ipv4Addr;
use std::net::SocketAddr;
use std::net::TcpListener;
use std::net::TcpStream;
use std::path::PathBuf;
use std::str::FromStr;
use std::thread;

pub mod http;
use crate::http::HttpMethod;
use crate::http::HttpRequest;
use crate::http::HttpResponse;
use crate::http::HttpStatus;
use http_server::ThreadPool;

const DEFAULT_SERVER_ADDRESS: &str = "127.0.0.1";
const DEFAULT_SERVER_PORT: u16 = 7878;
const DEFAULT_FILE_ROOT: &str = "www";
const DEFAULT_THREAD_POOL_SIZE: usize = 4;

fn main() -> Result<()> {
    let addr = build_server_addr()?;
    let listener = TcpListener::bind(addr)?;
    let pool = ThreadPool::new(DEFAULT_THREAD_POOL_SIZE);

    for stream in listener.incoming() {
        let stream = stream?;
        pool.execute(|| match handle_connection(stream) {
            Ok(_) => (),
            Err(err) => {
                eprintln!("Error: {}", err.to_string());
            }
        });
    }
    Ok(())
}

fn handle_connection(mut stream: TcpStream) -> Result<()> {
    let buf_reader = BufReader::new(&stream);
    let raw_http_lines: Vec<_> = buf_reader
        .lines()
        .filter(|line| line.is_ok())
        .map(|line| line.unwrap())
        .take_while(|line| !line.is_empty())
        .collect();
    let http_request = HttpRequest::new(raw_http_lines)?;
    println!("Request: {http_request:#?}");
    let http_response = match http_request.method {
        HttpMethod::GET => handle_http_get(http_request),
    }?;
    println!("Response: {http_response:#?}");
    println!("ResponseRaw:\n{}", http_response);
    let raw_http_response: String = http_response.try_into()?;
    stream.write_all(raw_http_response.as_bytes())?;
    Ok(())
}

fn handle_http_get(http_request: HttpRequest) -> Result<HttpResponse> {
    let path_parts: Vec<_> = http_request
        .path
        .split('?')
        .filter(|part| !part.is_empty())
        .map(|part| part.to_string())
        .collect();
    let path = match path_parts.first() {
        Some(path) => path,
        None => bail!("Invalid path string"),
    };

    let path = match path.as_str() {
        "/" => "index.html",
        path => {
            if path.starts_with("/") {
                path.trim_start_matches("/")
            } else {
                path
            }
        }
    };
    let response = match serve_file(path) {
        Ok(contents) => HttpResponse::new(HttpStatus::Ok, contents),
        Err(err) => HttpResponse::new(HttpStatus::NotFound, err.to_string()),
    };
    Ok(response)
}

fn serve_file(path: &str) -> Result<String> {
    let file_path = PathBuf::from(DEFAULT_FILE_ROOT).join(path);
    if !file_path.exists() {
        Err(anyhow!(format!(
            "File {} not found",
            file_path.to_string_lossy().to_string()
        )))
    } else {
        Ok(fs::read_to_string(file_path)?)
    }
}

fn build_server_addr() -> Result<SocketAddr> {
    Ok(SocketAddr::new(
        IpAddr::V4(Ipv4Addr::from_str(DEFAULT_SERVER_ADDRESS)?),
        DEFAULT_SERVER_PORT,
    ))
}
