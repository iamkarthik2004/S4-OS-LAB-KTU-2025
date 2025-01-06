echo "Enter limit: "
read limit
x=0
y=1
echo "Sequence is: "
echo -n " " $x
echo -n " " $y
for((i=2;i<=$limit;i++))
do
z=$(($x+$y))
echo -n " " $z
x=$y
y=$z
done



