#[cfg(test)]
mod tests {
    use s03_state_pattern::Post;

    #[test]
    fn test_state_pattern() {
        let mut post = Post::new();

        post.add_text("I ate a salad for lunch today");
        assert_eq!("", post.content());

        post.request_review();
        assert_eq!("", post.content());

        post.request_review();
        assert_eq!("", post.content());

        post.approve();
        assert_eq!("I ate a salad for lunch today", post.content());

        post.request_review();
        assert_eq!("I ate a salad for lunch today", post.content());
    }
}

fn main() {}
