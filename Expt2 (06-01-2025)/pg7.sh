echo "Enter First Number: "
read a
echo "Enter Second Number: "
read b


echo "Select any Option: "
read OP
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

