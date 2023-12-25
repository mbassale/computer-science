use std::thread;
use std::time::Duration;

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_thread() {
        let result = thread::spawn(|| {
            for _ in 1..10 {
                thread::sleep(Duration::from_millis(1));
            }
        })
        .join();
        assert!(result.is_ok());
    }

    #[test]
    fn test_thread_closures() {
        let v = vec![1, 2, 3];
        let handle = thread::spawn(move || {
            assert_eq!(v, vec![1, 2, 3]);
        });
        assert!(handle.join().is_ok());
    }
}

fn main() {
    println!("Hello, world!");
}
