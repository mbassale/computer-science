use std::fmt;

use anyhow::anyhow;
use anyhow::bail;
use anyhow::Error;
use anyhow::Result;
use regex::Regex;

#[derive(Debug)]
pub enum HttpMethod {
    GET,
}

impl TryInto<HttpMethod> for String {
    type Error = Error;

    fn try_into(self) -> Result<HttpMethod, Self::Error> {
        let method = match self.as_str() {
            "GET" => HttpMethod::GET,
            _ => bail!("Invalid HTTP Method"),
        };
        Ok(method)
    }
}

#[derive(Debug)]
pub struct HttpRequest {
    pub method: HttpMethod,
    pub path: String,
    pub version: String,
}

impl HttpRequest {
    pub fn new(raw_http_lines: Vec<String>) -> Result<HttpRequest> {
        let (method, path, version) = match raw_http_lines.first() {
            Some(header) => {
                let re = Regex::new(r"(GET|HEAD) ([^\s]+) (HTTP/\d.\d)$")?;
                if let Some(captures) = re.captures(header) {
                    let method: HttpMethod = captures
                        .get(1)
                        .ok_or(anyhow!("Missing method"))?
                        .as_str()
                        .to_string()
                        .try_into()?;
                    let path = captures
                        .get(2)
                        .ok_or(anyhow!("Missing path"))?
                        .as_str()
                        .to_string();
                    let version = captures
                        .get(3)
                        .ok_or(anyhow!("Missing version"))?
                        .as_str()
                        .to_string();
                    (method, path, version)
                } else {
                    anyhow::bail!("Invalid http request");
                }
            }
            None => {
                anyhow::bail!("Empty http request");
            }
        };
        Ok(HttpRequest {
            method,
            path,
            version,
        })
    }
}

#[derive(Debug)]
pub enum HttpStatus {
    Ok,
    NotFound,
}

impl fmt::Display for HttpStatus {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let (status_code, status_str) = match self {
            Self::Ok => (200, "OK"),
            Self::NotFound => (404, "NotFound"),
        };
        write!(f, "{} {}", status_code, status_str)
    }
}

impl TryInto<String> for HttpResponse {
    type Error = Error;

    fn try_into(self) -> std::prelude::v1::Result<String, Self::Error> {
        Ok(format!("{}", self))
    }
}

#[derive(Debug)]
pub struct HttpResponse {
    pub version: String,
    pub status: HttpStatus,
    pub body: String,
}

impl HttpResponse {
    pub fn new(status: HttpStatus, body: String) -> HttpResponse {
        HttpResponse {
            version: "HTTP/1.1".to_string(),
            status,
            body,
        }
    }
}

impl fmt::Display for HttpResponse {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        if self.body.is_empty() {
            write!(f, "HTTP/1.1 {}\r\n\r\n", self.status)
        } else {
            write!(f, "HTTP/1.1 {}\r\n\r\n{}\r\n", self.status, self.body)
        }
    }
}
