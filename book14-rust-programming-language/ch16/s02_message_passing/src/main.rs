use std::sync::mpsc;
use std::thread;

#[cfg(test)]
mod test {
    use std::time::Duration;

    use super::*;

    #[test]
    fn test_channel() {
        let (tx, rx) = mpsc::channel();

        thread::spawn(move || {
            let val = String::from("test1");
            let result = tx.send(val);
            assert!(result.is_ok());
        });

        let received = rx.recv();
        assert!(received.is_ok());
        assert_eq!(received, Ok("test1".to_string()));
    }

    #[test]
    fn test_multiple_values() {
        let (tx, rx) = mpsc::channel();

        thread::spawn(move || {
            let vals = vec![
                String::from("test1"),
                String::from("test2"),
                String::from("test3"),
                String::from("test4"),
            ];

            for val in vals {
                tx.send(val).unwrap();
                thread::sleep(Duration::from_secs(1));
            }
        });

        assert_eq!(
            rx.iter().collect::<Vec<String>>(),
            vec!["test1", "test2", "test3", "test4"]
                .iter()
                .map(|str| str.to_string())
                .collect::<Vec<String>>()
        );
    }

    #[test]
    fn test_multiple_producers() {
        let (tx, rx) = mpsc::channel();

        let tx1 = tx.clone();
        thread::spawn(move || {
            let vals = vec![1,2,3,4,5];
            for val in vals {
                tx1.send(val).unwrap();
                thread::sleep(Duration::from_secs(1));
            }
        });

        thread::spawn(move || {
            let vals = vec![6,7,8,9,10];
            for val in vals {
                tx.send(val).unwrap();
                thread::sleep(Duration::from_secs(1));
            }
        });

        let mut results = rx.iter().collect::<Vec<i32>>();
        results.sort();
        assert_eq!(results, vec![1,2,3,4,5,6,7,8,9,10]);
    }
}

fn main() {}
