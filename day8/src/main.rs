use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::cmp::Ordering;
use std::cmp::min;
use std::cmp::max;

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

fn scenic_score(grid: &Grid, x: usize, y: usize) -> u32 {
    let mut viewing_distances = [x, grid.len() - x -1, y, grid.len() - y - 1];
    let height = grid[x][y];
    for i in 0..grid.len() {
	if grid[i][y] >= height {
	    match i.cmp(&x) {
		Ordering::Less => {viewing_distances[0] = x - i;},
		Ordering::Greater => {viewing_distances[1] = min(i - x, viewing_distances[1]);},
		Ordering::Equal => (),
	    }
	}
	if grid[x][i] >= height {
	    match i.cmp(&y) {
		Ordering::Less => {viewing_distances[2] = y - i;},
		Ordering::Greater => {viewing_distances[3] = min(i - y, viewing_distances[3]);},
		Ordering::Equal => (),
	    }	    
	}
    }
    viewing_distances.into_iter().fold(1, |vis, sc| vis * u32::try_from(sc).unwrap())
}

fn max_scenic_score(grid: &Grid) -> u32 {
    let mut max_score = 0_u32;
    for x in 0..grid.len() {
	for y in 0..grid.len() {
	    let score = scenic_score(grid, x, y);
	    max_score = max(max_score, score);
	}
    }
    max_score
}

fn main() {
    let grid = read_grid();
    println!("{}", max_scenic_score(&grid));
}
