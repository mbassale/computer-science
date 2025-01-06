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

pub mod http;
use crate::http::HttpRequest;
use crate::http::HttpResponse;
use crate::http::HttpStatus;

const SERVER_PORT: u16 = 7878;

fn main() -> Result<()> {
    let addr = build_server_addr();
    let listener = TcpListener::bind(addr)?;
    for stream in listener.incoming() {
        let stream = stream?;
        handle_connection(stream)?;
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
    let contents = fs::read_to_string("www/index.html")?;
    let http_response = HttpResponse::new(HttpStatus::Ok, contents);
    println!("Response: {http_response:#?}");
    println!("ResponseRaw:\n{}", http_response);
    let raw_http_response: String = http_response.try_into()?;
    stream.write_all(raw_http_response.as_bytes())?;
    Ok(())
}

fn build_server_addr() -> SocketAddr {
    SocketAddr::new(IpAddr::V4(Ipv4Addr::new(127, 0, 0, 1)), SERVER_PORT)
}
