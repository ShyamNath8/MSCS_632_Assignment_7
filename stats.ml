let mean lst =
  let sum = List.fold_left ( + ) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 1 then
    float_of_int (List.nth sorted (n / 2))
  else
    let a = List.nth sorted (n/2 - 1) in
    let b = List.nth sorted (n/2) in
    (float_of_int a +. float_of_int b) /. 2.0

let mode lst =
  let sorted = List.sort compare lst in
  let rec count current count_max current_count modes = function
    | [] ->
        if current_count = count_max then current :: modes
        else if current_count > count_max then [current]
        else modes
    | x :: xs ->
        if x = current then
          count current count_max (current_count + 1) modes xs
        else
          let new_modes =
            if current_count = count_max then current :: modes
            else if current_count > count_max then [current]
            else modes
          in
          count x (max count_max current_count) 1 new_modes xs
  in
  match sorted with
  | [] -> []
  | x :: xs -> count x 1 1 [] xs

let () =
  let data = [4; 1; 2; 2; 5; 3; 3] in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);

  let m = mode data in
  Printf.printf "Mode(s): ";
  List.iter (fun x -> Printf.printf "%d " x) m;
  print_endline ""
