use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::cmp::Ordering;

type Grid = Vec<Vec<u32>>;

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn read_grid() -> Grid {
    let mut grid: Grid = Vec::new();
    if let Ok(lines) = read_lines("input") {
	for content in lines.flatten() {
		let mut grid_row: Vec<u32> = Vec::new();
		for val in content.chars() {
		    grid_row.push(val.to_digit(10).unwrap());
		}
		grid.push(grid_row);
	}
    }
    grid
}

fn is_visible(grid: &Grid, x: usize, y: usize) -> bool {
    let mut visible = [true, true, true, true];
    let height = grid[x][y];
    for i in 0..grid.len() {
	if grid[i][y] >= height {
	    match i.cmp(&x) {
		Ordering::Less => {visible[0] = false;},
		Ordering::Greater => {visible[1] = false;},
		Ordering::Equal => (),
	    }
	}
	if grid[x][i] >= height {
	    match i.cmp(&y) {
		Ordering::Less => {visible[2] = false;},
		Ordering::Greater => {visible[3] = false;},
		Ordering::Equal => (),
	    }	    
	}
    }
    visible.into_iter().fold(false, |vis, x| vis || x)
}

fn count_visible(grid: &Grid) -> u32 {
    let mut counter = 0_u32;
    for x in 0..grid.len() {
	for y in 0..grid.len() {
	    if is_visible(grid, x, y){
		counter += 1;
	    }
	}
    }
    counter
}

fn main() {
    let grid = read_grid();
    println!("{}", count_visible(&grid));
}
