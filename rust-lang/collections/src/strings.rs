pub fn run() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}

fn test1() {
    let data = "initial contents";
    dbg!(data);
    let s = data.to_string();
    dbg!(s);
}

fn test2() {
    let mut s = String::from("foo");
    dbg!(&s);
    s.push_str("bar");
    dbg!(s);
}

fn test3() {
    let s1 = String::from("Hello, ");
    dbg!(&s1);
    let s2 = String::from("world!");
    dbg!(&s2);
    let s3 = s1 + &s2;
    dbg!(s3);
}

fn test4() {
    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");
    let s = format!("{}-{}-{}", s1, s2, s3);
    dbg!(&s);
}

fn test5() {
    let hello = "Здравствуйте";
    let s = &hello[0..4];
    dbg!(s);
}

fn test6() {
    for c in "नमस्ते".chars() {
        println!("{}", c);
    }
    for b in "नमस्ते".bytes() {
        println!("{}", b);
    }
}
