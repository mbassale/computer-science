#[cfg(test)]
mod tests {
    use std::{sync::Arc, sync::Mutex, thread};

    #[test]
    fn test_mutex() {
        let m = Mutex::new(5);

        {
            let mut num = m.lock().unwrap();
            *num = 6;
        }

        assert_eq!(*m.lock().unwrap(), 6);
    }

    #[test]
    fn test_sharing_mutex() {
        let counter = Arc::new(Mutex::new(0));
        let mut handles = vec![];

        for _ in 0..10 {
            let counter = Arc::clone(&counter);
            let handle = thread::spawn(move || {
                let mut num = counter.lock().unwrap();
                *num += 1;
            });
            handles.push(handle);
        }

        for handle in handles {
            handle.join().unwrap();
        }

        assert_eq!(*counter.lock().unwrap(), 10);
    }
}
fn main() {
    println!("Hello, world!");
}
