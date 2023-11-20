use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

#[named]
fn test1_match() {
    trace(function_name!());
    let config_max = Some(3u8);
    match config_max {
        Some(max) => println!("config_max: {max}"),
        _ => (),
    }

    let config_max = Some(3u8);
    if let Some(max) = config_max {
        println!("config_max: {max}");
    }
}

fn main() {
    test1_match();
}
