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
	if self.player == winning_action(self.opponent) {
	    outcome_score = 6;
	}
	self.player + outcome_score
    }
}

struct ParseInputError;

fn winning_action(action: i32) -> i32{
    action % 3 + 1
}

fn losing_action(action: i32) -> i32{
    if action == 1 {
	return 3;
    }
    action - 1
}

fn decode_opponent_action(code: &str) -> Result<i32, ParseInputError>{
    match code {
	"A" => Ok(1),
	"B" => Ok(2),
	"C" => Ok(3),
	_ => Err(ParseInputError),
    }
}

fn decode_player_action(code: &str, op_action: i32) -> Result<i32, ParseInputError>{
    match code {
	"X" => Ok(losing_action(op_action)),
	"Y" => Ok(op_action),
	"Z" => Ok(winning_action(op_action)),
	_ => Err(ParseInputError),
    }
}

impl FromStr for RPSMatch {
    type Err = ParseInputError;
    fn from_str(line: &str) -> Result<Self, Self::Err> {
	let mut parts = line.split(' ');
	let opponent_action = decode_opponent_action(parts.next().ok_or(ParseInputError)?)?;
	let player_action = decode_player_action(parts.next().ok_or(ParseInputError)?, opponent_action)?;
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
    println!("{}", get_total_score(&matches));
}
