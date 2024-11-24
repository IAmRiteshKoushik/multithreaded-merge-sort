pub mod merge_sort;
pub mod mth_merge_sort;

use crate::merge_sort::merge_sort;
use crate::mth_merge_sort::mth_merge_sort;

use rand::Rng;
use std::time::Instant;
use std::io;
use std::sync::{Arc, Mutex};

fn main() {
    println!("Enter the size of the array: ");
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let size: usize = input.trim().parse().unwrap();

    let mut arr: Vec<i32> = (0..size)
        .map(|_| rand::thread_rng().gen_range(1..size as i32))
        .collect();

    
    let start_merge = Instant::now();
    merge_sort(&mut arr);
    let merge_duration = start_merge.elapsed();

    let arr_arc = Arc::new(Mutex::new(arr));
    let mth_start = Instant::now();
    mth_merge_sort(Arc::clone(&arr_arc));
    let mth_duration = mth_start.elapsed(); 

    println!("Normal Merge Sorting completed in {:.2?}", merge_duration);
    println!("Multithreaded Merge Sorting completed in {:.2?}", mth_duration);
}

