#![allow(dead_code)]

pub struct AveragedCollection {
    list: Vec<i32>,
    average: f64,
}

impl AveragedCollection {
    pub fn new() -> AveragedCollection {
        AveragedCollection {
            list: vec![],
            average: 0.0,
        }
    }

    pub fn add(&mut self, value: i32) {
        self.list.push(value);
        self.update_average();
    }

    pub fn remove(&mut self) -> Option<i32> {
        let result = self.list.pop();
        match result {
            Some(value) => {
                self.update_average();
                Some(value)
            }
            None => None,
        }
    }

    pub fn average(&self) -> f64 {
        self.average
    }

    fn update_average(&mut self) {
        let total: i32 = self.list.iter().sum();
        self.average = total as f64 / self.list.len() as f64;
    }
}

#[cfg(test)]
mod tests {
    use crate::AveragedCollection;

    #[test]
    fn test_object() {
        let nums = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
        let mut avg_coll = AveragedCollection::new();
        for num in nums {
            avg_coll.add(num);
            let actual_avg = avg_coll.average();
            let expected_avg = (num + 1) as f64 / 2.0;
            assert_eq!(actual_avg, expected_avg);
        }
    }
}

fn main() {}
