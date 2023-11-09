use std::error::Error;
use std::fs::File;
use std::io::{self, ErrorKind, Read};

fn main() -> Result<(), Box<dyn Error>> {
    test1();
    test2();
    test3();
    test4();
    Ok(())
}

fn test1() {
    let f = File::open("hello.txt");
    let f = match f {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("Problem creating the file: {:?}", e),
            },
            other_error => {
                panic!("Problem opening the file: {:?}", other_error)
            }
        },
    };
    dbg!(f);
}

fn test2() {
    let file_name = "hello.txt";
    let error_msg = format!("Failed to open {}", file_name);
    let f = File::open(file_name).expect(&String::from(error_msg));
    dbg!(f);
}

fn test3() {
    let username = read_username_from_file().expect("Error reading username");
    dbg!(username);
}

fn test4() {
    let username = read_username_from_file2();
    dbg!(username);
}

fn read_username_from_file() -> Result<String, io::Error> {
    let f = File::open("hello.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();
    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}

fn read_username_from_file2() -> Result<String, io::Error> {
    let mut s = String::new();
    File::open("hello.txt")?.read_to_string(&mut s)?;
    Ok(s)
}
