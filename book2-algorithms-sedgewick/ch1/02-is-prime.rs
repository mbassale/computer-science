/*
$ ./02-is-prime
is_prime(1) = false
is_prime(2) = true
is_prime(3) = true
is_prime(4) = false
is_prime(5) = true
is_prime(6) = false
is_prime(7) = true
is_prime(8) = false
is_prime(9) = false
is_prime(10) = false
is_prime(11) = true
is_prime(12) = false
is_prime(13) = true
is_prime(14) = false
is_prime(15) = false
is_prime(16) = false
is_prime(17) = true
is_prime(18) = false
is_prime(19) = true
is_prime(20) = false
is_prime(21) = false
is_prime(22) = false
is_prime(23) = true
is_prime(24) = false
is_prime(25) = false
is_prime(26) = false
is_prime(27) = false
is_prime(28) = false
is_prime(29) = true
is_prime(30) = false
is_prime(31) = true
is_prime(32) = false
is_prime(33) = false
is_prime(34) = false
is_prime(35) = false
is_prime(36) = false
is_prime(37) = true
is_prime(38) = false
is_prime(39) = false
is_prime(40) = false
is_prime(41) = true
is_prime(42) = false
is_prime(43) = true
is_prime(44) = false
is_prime(45) = false
is_prime(46) = false
is_prime(47) = true
is_prime(48) = false
is_prime(49) = false
is_prime(50) = false
is_prime(51) = false
is_prime(52) = false
is_prime(53) = true
is_prime(54) = false
is_prime(55) = false
is_prime(56) = false
is_prime(57) = false
is_prime(58) = false
is_prime(59) = true
is_prime(60) = false
is_prime(61) = true
is_prime(62) = false
is_prime(63) = false
is_prime(64) = false
is_prime(65) = false
is_prime(66) = false
is_prime(67) = true
is_prime(68) = false
is_prime(69) = false
is_prime(70) = false
is_prime(71) = true
is_prime(72) = false
is_prime(73) = true
is_prime(74) = false
is_prime(75) = false
is_prime(76) = false
is_prime(77) = false
is_prime(78) = false
is_prime(79) = true
is_prime(80) = false
is_prime(81) = false
is_prime(82) = false
is_prime(83) = true
is_prime(84) = false
is_prime(85) = false
is_prime(86) = false
is_prime(87) = false
is_prime(88) = false
is_prime(89) = true
is_prime(90) = false
is_prime(91) = false
is_prime(92) = false
is_prime(93) = false
is_prime(94) = false
is_prime(95) = false
is_prime(96) = false
is_prime(97) = true
is_prime(98) = false
is_prime(99) = false
*/

fn is_prime(x: i32) -> bool {
    if x < 2 {
        return false;
    }
    let mut i = 2;
    while i * i <= x {
        if x % i == 0 {
            return false;
        }
        i += 1;
    }
    return true;
}

fn main() {
    for i in 1..100 {
        println!("is_prime({i}) = {}", is_prime(i));
    }
}
