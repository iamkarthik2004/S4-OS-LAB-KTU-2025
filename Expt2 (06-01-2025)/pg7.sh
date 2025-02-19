#Write a program to implement a simple calculator

echo "1. Addition"
echo "2. Addition"
echo "3. Multiplication"
echo "4. Division"

echo "Select any Option: "
read OP
echo "Enter First Number: "
read a
echo "Enter Second Number: "
read b
case $OP in
1)C=$(($a+$b))
echo "Sum is: $C";;
2)C=$(($a-$b))
echo "Difference is: $C";;
3)C=$(($a*$b))
echo "Product is: $C";;
4)C=$(($a/$b))
echo "Division is: $C";;
*)echo "Wrong choice";;
esac
