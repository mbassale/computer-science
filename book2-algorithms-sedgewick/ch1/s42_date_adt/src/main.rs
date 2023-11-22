use std::fmt;

struct Date1 {
    month: u8,
    day: u8,
    year: u16,
}

impl Date1 {
    fn new(m: u8, d: u8, y: u16) -> Date1 {
        Date1 {
            month: m,
            day: d,
            year: y,
        }
    }

    fn month(&self) -> u8 {
        self.month
    }

    fn day(&self) -> u8 {
        self.day
    }

    fn year(&self) -> u16 {
        self.year
    }
}

impl fmt::Display for Date1 {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}/{}/{}", self.month(), self.day(), self.year())
    }
}

struct Date2 {
    value: u32,
}

impl Date2 {
    fn new(m: u32, d: u32, y: u32) -> Date2 {
        Date2 {
            value: y * 512 + m * 32 + d,
        }
    }

    fn month(&self) -> u8 {
        ((self.value / 32) % 16) as u8
    }

    fn day(&self) -> u8 {
        (self.value % 32) as u8
    }

    fn year(&self) -> u16 {
        (self.value / 512) as u16
    }
}

impl fmt::Display for Date2 {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}/{}/{}", self.month(), self.day(), self.year())
    }
}

fn main() {
    let test_cases: Vec<(u8, u8, u16)> = vec![(11, 22, 2023), (8, 15, 1984), (12, 10, 2001)];
    for (m, d, y) in test_cases {
        let date1 = Date1::new(m, d, y);
        println!("Date1: {date1}");
        let date2 = Date2::new(m.into(), d.into(), y.into());
        println!("Date2: {date2}");
    }
}
