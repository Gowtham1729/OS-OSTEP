for((i=1;i<=100000;i=i*2))
do
	time=$(./tlb $i 100)
	echo "$i,100,$time" >> data.txt
	echo "$i"
done
