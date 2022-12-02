use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn read_input() -> Vec<i32> {
    let mut accumulated: i32 = 0;
    let mut acc_vals: Vec<i32> = Vec::new();
    if let Ok(lines) = read_lines("input") {
	for line in lines {
	    if let Ok(content) = line {
		if let Ok(value) = content.parse::<i32>() {
		    accumulated += value;
		}
		else {
		    acc_vals.push(accumulated);
		    accumulated = 0;
		}
	    }
	}
    }
    acc_vals.push(accumulated);
    acc_vals
}

fn get_highest_values(mut buf: Vec<i32>, n_values: usize) {
    buf.sort();
    buf.reverse();
    for val in &buf[0..n_values] {
	println!("{}", val);
    }
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn main() {
    let acc_vals = read_input();
    get_highest_values(acc_vals, 3);
}
