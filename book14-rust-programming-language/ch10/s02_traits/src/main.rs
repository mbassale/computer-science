use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

pub trait Summary {
    fn summarize(&self) -> String {
        String::from("(Read more...)")
    }
}

#[derive(Debug)]
pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

impl Summary for NewsArticle {}

#[derive(Debug)]
pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }
}

#[named]
fn test1_trait() {
    trace(function_name!());
    let tweet = Tweet {
        username: String::from("mbassale"),
        content: String::from("lorem ipsum dolor senet"),
        reply: false,
        retweet: false,
    };
    let tweet = dbg!(tweet);
    println!("1 new tweet: {}", tweet.summarize());

    let article = NewsArticle {
        headline: String::from("headline"),
        location: String::from("location"),
        author: String::from("mbassale"),
        content: String::from("lorem ipsum dolor senet"),
    };
    let article = dbg!(article);
    println!("New article: {}", article.summarize());
}

pub fn notify(item: &impl Summary) {
    println!("Breaking news! {}", item.summarize());
}

#[named]
fn test2_trait_arguments() {
    trace(function_name!());
    let tweet = Tweet {
        username: String::from("mbassale"),
        content: String::from("Lorem ipsum"),
        reply: true,
        retweet: true
    };
    notify(&tweet);
}

fn main() {
    test1_trait();
    test2_trait_arguments();
}
