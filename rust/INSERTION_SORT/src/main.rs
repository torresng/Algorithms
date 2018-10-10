fn insertion_sort(A: &mut[i64]) {
    for j in 1..A.len() {
        let key: i64 = A[j];
        for i in (0..j).rev() {
            if A[i] <= key {
                break;
            }
            A.swap(i + 1, i);
        }
    }
}

fn main() {
    let mut a = [5, 2, 4, 6, 1, 3];
    insertion_sort(&mut a);
    for v in a.iter() {
        print!("{}", v)
    }
    //a = insertion_sort(a);
    //println!("{:?}", a);
}
