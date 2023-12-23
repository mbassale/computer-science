#![allow(dead_code)]

#[derive(Debug, PartialEq)]
pub enum MessageType {
    HardLimit,
    SoftLimit,
    WarningLimit,
}

pub trait Messenger {
    fn send(&self, msg: MessageType);
}

pub struct LimitTracker<'a, T: Messenger> {
    messenger: &'a T,
    value: usize,
    max: usize,
}

impl<'a, T> LimitTracker<'a, T>
where
    T: Messenger,
{
    pub fn new(messenger: &'a T, max: usize) -> LimitTracker<'a, T> {
        LimitTracker {
            messenger,
            value: 0,
            max,
        }
    }

    pub fn set_value(&mut self, value: usize) {
        self.value = value;

        let percentage_of_max = self.value as f64 / self.max as f64;

        if percentage_of_max >= 1.0 {
            self.messenger.send(MessageType::HardLimit);
        } else if percentage_of_max >= 0.9 {
            self.messenger.send(MessageType::SoftLimit);
        } else if percentage_of_max >= 0.75 {
            self.messenger.send(MessageType::WarningLimit);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::cell::RefCell;

    struct MockMessenger {
        sent_messages: RefCell<Vec<MessageType>>,
    }

    impl MockMessenger {
        fn new() -> MockMessenger {
            MockMessenger {
                sent_messages: RefCell::new(vec![]),
            }
        }
    }

    impl Messenger for MockMessenger {
        fn send(&self, msg: MessageType) {
            self.sent_messages.borrow_mut().push(msg);
        }
    }

    #[test]
    fn it_sends_correct_warning_messages() {
        let mock_messenger = MockMessenger::new();
        let mut limit_tracker = LimitTracker::new(&mock_messenger, 100);
        limit_tracker.set_value(80);
        limit_tracker.set_value(90);
        limit_tracker.set_value(100);
        let sent_messages = mock_messenger.sent_messages.borrow();
        assert_eq!(sent_messages.len(), 3);
        assert_eq!(
            sent_messages.iter().collect::<Vec<&MessageType>>(),
            vec![
                &MessageType::WarningLimit,
                &MessageType::SoftLimit,
                &MessageType::HardLimit
            ]
        );
    }
}

fn main() {}
