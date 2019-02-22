fn insertion_sort(arr: &mut [i32]) {
    for j in 1..arr.len() {
        for i in (0..j).rev() {
            if arr[i] > arr[i + 1] {
                let key = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = key;
            } else {
                break;
            }
        }
    }
}

fn main() {
    let mut arr: [i32; 6] = [5, 2, 4, 6, 1, 3];
    insertion_sort(&mut arr);

    println!("{:?}", arr);
}
