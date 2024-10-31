const MOD: u64 = 7 + 1e9 as u64;

fn fibo(x: u64) -> (u64, u64) {
    if x == 1 {
        return (1, 0);
    }

    let half = fibo(x / 2);

    return |x: (u64, u64), y: (u64, u64)| -> (u64, u64) {
        (((x.0 + x.1) * y.0 + x.0 * y.1) % MOD, (x.0 * y.0 + x.1 * y.1) % MOD)
    }(half, if x % 2 == 1 {(half.0 + half.1, half.0)} else {half});
}

fn solve(input: &str) -> u64 {
    let res: (u64, u64) = fibo(input.parse::<u64>().unwrap() + 1);
    return res.0 * res.1 % MOD;
}

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_line(&mut input)
        .unwrap();

    print!("{}", solve(input.trim()));
}
