use function_name::named;
use std::fs::{self, File};
use std::io::{self, ErrorKind, Read};

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

#[named]
fn test1_open() {
    trace(function_name!());

    const FILENAME: &str = "hello.txt";
    let greeting_file_result = File::open(FILENAME);
    match greeting_file_result {
        Ok(file) => println!("file: {:?}", file),
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create(FILENAME) {
                Ok(_) => println!("File successfully created"),
                Err(e) => println!("Error creating the file: {:?}", e),
            },
            other_error => println!("Problem opening the file: {:?}", other_error),
        },
    };
    match std::fs::remove_file(FILENAME) {
        Ok(_) => println!("File delete: {:?}", FILENAME),
        Err(error) => println!("Error deleting file: {FILENAME}. {:?}", error),
    };
}

#[named]
fn read_username_from_file() -> Result<String, io::Error> {
    trace(function_name!());
    let username_file_result = File::open("hello.txt");
    let mut username_file = match username_file_result {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut username = String::new();
    match username_file.read_to_string(&mut username) {
        Ok(_) => Ok(username),
        Err(e) => Err(e),
    }
}

#[named]
fn read_username_from_file_shortcut() -> Result<String, io::Error> {
    trace(function_name!());
    let mut username_file = File::open("hello.txt")?;
    let mut username = String::new();
    username_file.read_to_string(&mut username)?;
    Ok(username)
}

#[named]
fn read_username_from_file_shortest() -> Result<String, io::Error> {
    trace(function_name!());
    fs::read_to_string("hello.txt")
}

#[named]
fn test2_propagating_errors() {
    trace(function_name!());
    let username = match read_username_from_file() {
        Ok(username) => username,
        Err(err) => String::from(format!("Error: {:?}", err)),
    };
    println!("Username #1: {username}");

    let username = match read_username_from_file_shortcut() {
        Ok(username) => username,
        Err(err) => String::from(format!("Error: {:?}", err)),
    };
    println!("Username #2: {username}");

    let username = match read_username_from_file_shortest() {
        Ok(username) => username,
        Err(err) => String::from(format!("Error: {:?}", err)),
    };
    println!("Username #3: {username}");
}

fn main() {
    test1_open();
    test2_propagating_errors();
}
