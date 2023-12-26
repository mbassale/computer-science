#[cfg(test)]
mod tests {
    use s04_state_pattern_v2::Post;

    #[test]
    fn test_state_pattern() {
        let mut post = Post::new();
        post.add_text("I ate salad for lunch today");

        let post = post.request_review();
        let post = post.approve();
        assert_eq!("I ate salad for lunch today", post.content());
    }
}

fn main() {}
