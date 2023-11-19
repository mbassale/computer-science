use function_name::named;
use rand::Rng;
use std::fmt;

const NUM_TRIALS: u32 = 10000000;

fn trace(s: &str) {
    println!("===== Calling {s} =====");
}

struct Counter {
    id: String,
    value: u32,
}

impl Counter {
    fn new(id: &str) -> Counter {
        Counter {
            id: String::from(id),
            value: 0,
        }
    }

    fn max(counter1: &Counter, counter2: &Counter) -> Counter {
        Counter {
            id: String::from("max"),
            value: std::cmp::max(counter1.tally(), counter2.tally()),
        }
    }

    fn increment(&mut self) {
        self.value += 1;
    }

    fn tally(&self) -> u32 {
        self.value
    }
}

impl fmt::Debug for Counter {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "Counter {{ id: {}, value: {} }}", self.id, self.value)
    }
}

#[named]
fn test0_counter() {
    trace(function_name!());
    let mut rng = rand::thread_rng();
    let mut heads = Counter::new("heads");
    let mut tails = Counter::new("tails");
    for _ in 1..=NUM_TRIALS {
        let number: f64 = rng.gen();
        if number < 0.5 {
            heads.increment();
        } else {
            tails.increment();
        }
    }

    let delta: u32;
    if heads.tally() > tails.tally() {
        delta = heads.tally() - tails.tally();
    } else {
        delta = tails.tally() - heads.tally();
    }

    let heads = dbg!(heads);
    let tails = dbg!(tails);
    println!("delta: {delta}");
    dbg!(Counter::max(&heads, &tails));
}

#[named]
fn test1_rolling_dice_simulation() {
    trace(function_name!());
    const SIDES: usize = 6;
    let mut rolls: [Counter; SIDES] = [
        Counter::new("1s"),
        Counter::new("2s"),
        Counter::new("3s"),
        Counter::new("4s"),
        Counter::new("5s"),
        Counter::new("6s"),
    ];

    let mut rng = rand::thread_rng();
    for _ in 1..=NUM_TRIALS {
        let result: usize = rng.gen_range(1..=SIDES);
        rolls[result - 1].increment()
    }

    for counter in rolls {
        dbg!(counter.tally());
    }
}

fn main() {
    test0_counter();
    test1_rolling_dice_simulation();
}
