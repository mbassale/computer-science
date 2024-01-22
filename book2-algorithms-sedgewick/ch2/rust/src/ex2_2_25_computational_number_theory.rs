/*
* [Sedgewick][Ch2] Exercise 2.4.25 Computational Number Theory.
* Using a min heap to calculate the sorted series of a^3 + b^3 when a,b are in range [0..100].
*/
#![allow(dead_code)]

#[derive(Debug)]
struct MinPQ {
    data: Vec<(u64, u64, u64)>,
}

impl MinPQ {
    fn new(sz: usize) -> MinPQ {
        let mut min_pq = MinPQ {
            data: vec![(0, 0, 0)],
        };
        min_pq.data.reserve(sz);
        min_pq
    }

    fn size(&self) -> usize {
        self.data.len() - 1
    }

    fn insert(&mut self, datum: (u64, u64, u64)) {
        self.data.push(datum);
        self.swim(self.data.len() - 1);
    }

    fn del_min(&mut self) -> (u64, u64, u64) {
        let min_value = self.data.swap_remove(1);
        self.sink(1);
        min_value
    }

    fn swim(&mut self, k: usize) {
        let mut k = k;
        while k > 0 && self.data[k / 2].0 > self.data[k].0 {
            self.data.swap(k / 2, k);
            k = k / 2;
        }
    }

    fn sink(&mut self, k: usize) {
        let mut k = k;
        while 2 * k < self.data.len() {
            let mut j = 2 * k;
            if j < self.data.len() - 1 && self.data[j].0 > self.data[j + 1].0 {
                j += 1;
            }
            if self.data[j].0 >= self.data[k].0 {
                break;
            }
            self.data.swap(j, k);
            k = j;
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::ex2_2_25_computational_number_theory::MinPQ;

    #[test]
    fn test_a3_plus_b3() {
        const N: usize = 100;
        let mut min_pq = MinPQ::new(N + 1);
        for i in 0..=N {
            min_pq.insert(((i as u64).pow(3), i as u64, 0));
        }

        let mut result = Vec::new();
        while min_pq.size() > 0 {
            let (value, a, b) = min_pq.del_min();
            result.push(value);
            if b < (N as u64) {
                min_pq.insert((a.pow(3) + (b + 1).pow(3), a, b + 1));
            }
        }
        assert!(result.len() >= 10000);
        assert_eq!(result.first().unwrap(), &0);
        assert_eq!(result.last().unwrap(), &2000000);
    }
}
