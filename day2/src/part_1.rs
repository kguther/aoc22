use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::str::FromStr;

struct RPSMatch {
    player: i32,
    opponent: i32,
}

impl RPSMatch{
    fn score(&self) -> i32{
	let mut outcome_score = 0;
	if self.player == self.opponent{
	    outcome_score = 3;
	}
	if self.player == self.opponent % 3 + 1 {
	    outcome_score = 6;
	}
	self.player + outcome_score
    }
}

struct ParseInputError;

fn decode_guide(code: &str) -> Result<i32, ParseInputError>{
    match code {
	"A"|"X" => Ok(1),
	"B"|"Y" => Ok(2),
	"C"|"Z" => Ok(3),
	_ => Err(ParseInputError),
    }
}

impl FromStr for RPSMatch {
    type Err = ParseInputError;
    fn from_str(line: &str) -> Result<Self, Self::Err> {
	let mut parts = line.split(' ');
	let opponent_action = decode_guide(parts.next().ok_or(ParseInputError)?)?;
	let player_action = decode_guide(parts.next().ok_or(ParseInputError)?)?;
	Ok(RPSMatch{player: player_action, opponent: opponent_action})
    }
}

fn read_guide() -> Vec<RPSMatch> {
    let mut matches: Vec<RPSMatch> = Vec::new();
    if let Ok(lines) = read_lines("input") {
	for line in lines {
	    if let Ok(content) = line{
		if let Ok(rps_match) = content.parse::<RPSMatch>(){
		    matches.push(rps_match);
		}
	    }
	}
    }
    matches
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn get_total_score(matches: &Vec<RPSMatch>) -> i32 {
    let mut total_score = 0;
    for rps_match in matches{
	total_score += rps_match.score();
    }
    total_score
}

fn main() {
    let matches = read_guide();
    for rps_match in &matches{
	println!("{}, {}, {}", rps_match.player, rps_match.opponent, rps_match.score())
    }
    println!("{}", get_total_score(&matches));
}
