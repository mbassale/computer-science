#![allow(dead_code)]

use s02_traits::Draw;

struct SelectBox {
    width: u32,
    height: u32,
    options: Vec<String>,
}

impl Draw for SelectBox {
    fn draw(&self) {}
}

#[cfg(test)]
mod tests {
    use s02_traits::Button;
    use s02_traits::Screen;

    use crate::SelectBox;

    #[test]
    fn test_components() {
        let screen = Screen {
            components: vec![
                Box::new(SelectBox {
                    width: 75,
                    height: 10,
                    options: vec![
                        String::from("test1"),
                        String::from("test2"),
                        String::from("test3"),
                    ],
                }),
                Box::new(Button {
                    width: 50,
                    height: 10,
                    label: String::from("test4"),
                }),
            ],
        };

        screen.run();
    }
}

fn main() {}
