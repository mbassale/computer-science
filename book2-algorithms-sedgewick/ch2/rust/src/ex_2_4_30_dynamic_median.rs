#![allow(dead_code)]

#[derive(Debug)]
struct DynamicMedian {
    min_heap: Vec<f32>,
    max_heap: Vec<f32>,
}

enum HeapType {
    MinHeap,
    MaxHeap,
}

impl DynamicMedian {
    fn new() -> DynamicMedian {
        DynamicMedian {
            min_heap: vec![0.0],
            max_heap: vec![0.0],
        }
    }

    fn median(&self) -> f32 {
        (self.min_heap[1] + self.max_heap[1]) / 2.0
    }

    fn insert(&mut self, value: f32) {
        self.min_heap.push(value);
        self.swim(&HeapType::MinHeap, self.min_heap.len() - 1);
        self.max_heap.push(value);
        self.swim(&HeapType::MaxHeap, self.max_heap.len() - 1);
    }

    fn heap_invariant(&self, heap_type: &HeapType, i: usize, j: usize) -> bool {
        match heap_type {
            HeapType::MinHeap => self.min_heap[i] < self.min_heap[j],
            HeapType::MaxHeap => self.max_heap[i] > self.max_heap[j],
        }
    }

    fn exchange(&mut self, heap_type: &HeapType, i: usize, j: usize) {
        match heap_type {
            HeapType::MinHeap => self.min_heap.swap(i, j),
            HeapType::MaxHeap => self.max_heap.swap(i, j),
        }
    }

    fn swim(&mut self, heap_type: &HeapType, k: usize) {
        let mut k = k;
        while k > 1 && !self.heap_invariant(heap_type, k / 2, k) {
            self.exchange(heap_type, k / 2, k);
            k = k / 2;
        }
    }

    fn size(&self, heap_type: &HeapType) -> usize {
        match heap_type {
            HeapType::MinHeap => self.min_heap.len(),
            HeapType::MaxHeap => self.max_heap.len(),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::DynamicMedian;

    #[test]
    fn test_dynamic_median() {
        vec![vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
            .into_iter()
            .map(|c| c as f32)
            .collect::<Vec<f32>>()]
        .into_iter()
        .for_each(|test_case| {
            let mut dynamic_median = DynamicMedian::new();
            test_case.iter().for_each(|n| {
                dynamic_median.insert(*n);
            });
            dbg!(dynamic_median.median());
            dbg!(&dynamic_median);
        })
    }
}
