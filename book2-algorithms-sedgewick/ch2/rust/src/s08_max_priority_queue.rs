#![allow(dead_code)]

#[derive(Debug)]
struct MaxPQ<T> {
    data: Vec<T>,
}

impl<T: PartialOrd + Default> MaxPQ<T> {
    pub fn new() -> MaxPQ<T> {
        MaxPQ {
            data: vec![T::default()],
        }
    }

    pub fn is_empty(&self) -> bool {
        self.data.len() == 1
    }

    pub fn size(&self) -> usize {
        self.data.len() - 1
    }

    pub fn insert(&mut self, value: T) {
        self.data.push(value);
        self.swim(self.data.len() - 1);
    }

    pub fn del_max(&mut self) -> T {
        if self.data.len() < 2 {
            panic!("Empty MaxPQ");
        }
        let max_value = self.data.swap_remove(1);
        self.sink(1);
        max_value
    }

    fn swim(&mut self, k: usize) {
        let mut k = k;
        while k / 2 > 0 && self.data[k / 2] < self.data[k] {
            self.data.swap(k / 2, k);
            k = k / 2;
        }
    }

    fn sink(&mut self, k: usize) {
        let mut k = k;
        while 2 * k < self.data.len() {
            let mut j = 2 * k;
            if j < self.data.len() - 1 && self.data[j] < self.data[j + 1] {
                j += 1;
            }
            if j == self.data.len() - 1 {
                break;
            }
            self.data.swap(j, k);
            k = j;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::MaxPQ;

    #[test]
    fn test_maxpq_i32() {
        let mut maxpq: MaxPQ<i32> = MaxPQ::new();
        for i in 1..=10 {
            maxpq.insert(i);
        }
        assert!(!maxpq.is_empty());
        assert_eq!(maxpq.size(), 10);
        let mut values = Vec::new();
        while !maxpq.is_empty() {
            values.push(maxpq.del_max());
        }
        assert!(maxpq.is_empty());
        assert_eq!(maxpq.size(), 0);
        let expected: Vec<i32> = (1..11).rev().collect();
        assert_eq!(values, expected);
    }

    #[test]
    fn test_maxpq_f32() {
        let mut maxpq: MaxPQ<f32> = MaxPQ::new();
        let mut i: f32 = 0.0;
        let mut expected = Vec::new();
        while i < 10.0 {
            maxpq.insert(i);
            expected.push(i);
            i += 0.05;
        }
        expected.reverse();
        let mut actual = Vec::new();
        while !maxpq.is_empty() {
            actual.push(maxpq.del_max());
        }
        assert_eq!(actual, expected);
    }
}
