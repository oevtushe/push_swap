#!/bin/zsh

# Generate array with random numbers. (Without repeatings !)
# $1 -> Max integer to generate
# $2 -> Size of array to generate

function gen_rand_numbers() {
	cur_rand=0
	for ((j = 0; j < ${2}; j++))
	do
		cur_rand="$(( ${RANDOM} % ${1} ))"
		while [[ ${nums[(ie)${cur_rand}]} -le ${#nums} ]]
		do
			cur_rand="$(( ${RANDOM} % ${1} ))"
		done
		nums+="$cur_rand"
	done
}

# Function execute push_swap with checker N times.
#
# 1 -> Random number high bound
# 2 -> Run times
# 3 -> Count of numbers to generate

function run_test() {
	for ((k = 0; k < $2; k++))
	do
		nums=()
		gen_rand_numbers $1 $3
		ops=$(./push_swap ${nums})
		if [[ -n $ops ]]
		then
			op_cnt=$(echo $ops | wc -l)
			cur=$(echo $ops | ./checker ${nums})
		else
			cur="OK"
		fi
		if [[ ${cur_sc_opts[(ie)--print]} -le ${#cur_sc_opts} ]]
		then
			echo "{$nums}($(( op_cnt )))[$cur]"
		fi
		if [[ $cur != "OK" ]]
		then
			echo $cur
			echo "Failed combination is written in fail.txt"
			echo "${nums} [$cur]" >> fail.txt
			exit 5
		fi
	done
}

function print_using() {
	echo "Using: zsh rand.zsh [-sc] [[--print] [--save] [--sequence <start> <finish>] [--random <max_value> <count>]"
	echo "         [--test <max_value> <nums_cnt> <times>] [--test2 <max_value> <seq_bound> <times>]]"
	echo "         [--loop <max_value> <count> <times>]"
	exit -1
}

# Shift
idx=0

ps_opts=("-s" "-c")
sc_opts=("--sequence" "--random" "--print" "--save" "--loop" "--test" "--test2")
cur_sc_opts=()
cur_ps_opts=()

# Read options
for name in $argv
do
	if [[ ${ps_opts[(ie)${name}]} -le ${#ps_opts} ]]
	then
		idx=$((idx + 1))
		cur_ps_opts+="${name}"
	elif [[ ${sc_opts[(ie)${name}]} -le ${#sc_opts} ]]
	then
		idx=$((idx + 1))
		cur_sc_opts+="${name}"
	fi
done

v1=${argv[((${idx} + 1))]}
v2=${argv[((${idx} + 2))]}
if [[ $v1 == <-> ]] && [[ $v2 == <-> ]]
then
	if (( v1 < v2  ))
	then
		echo "Error: <max_value> must be less than or equal to <count>"
		exit 2
	fi
else
	print_using
fi

# --sequence || --random
if [[ ${cur_sc_opts[(ie)--sequence]} -le ${#cur_sc_opts} ]]
then
	nums=()
	nums=$(echo {${v1}..${v2}})
	ops=$(./push_swap ${nums})
	if [[ -n $ops ]]
	then
		op_cnt=$(echo $ops | wc -l)
		cur=$(echo $ops | ./checker ${nums})
	else
		cur="OK"
	fi
	if [[ ${cur_sc_opts[(ie)--print]} -le ${#cur_sc_opts} ]]
	then
		echo "{$nums}($(($op_cnt)))[$cur]"
	else
		echo "[$cur]"
	fi
	exit 0
elif [[ ${cur_sc_opts[(ie)--random]} -le ${#cur_sc_opts} ]]
then
	nums=()
	gen_rand_numbers $v1 $v2
	ops=$(./push_swap ${nums})
	if [[ -n $ops ]]
	then
		op_cnt=$(echo $ops | wc -l)
		cur=$(echo $ops | ./checker ${nums})
	else
		cur="OK"
	fi
	if [[ ${cur_sc_opts[(ie)--save]} -le ${#cur_sc_opts} ]]
	then
		echo "{${nums}}($(($op_cnt)))[$cur]" >> last_combination.txt
		echo "Saved to last_combination.txt"
	elif [[ ${cur_sc_opts[(ie)--print]} -le ${#cur_sc_opts} ]]
	then
		echo "{$nums}($(($op_cnt)))[$cur]"
	else
		echo "($(( op_cnt  )))[$cur]"
	fi
	exit 0
fi

# --test
#
# Option executes push_swap and checker N times on M numbers with K upper bound of numbers.
# v1 -> Random number highest bound
# v2 -> Count of random numbers to generate
# v3 -> Times to execute

if [[ ${cur_sc_opts[(ie)--test]} -le ${#cur_sc_opts} ]]
then
	v3=${argv[((${idx} + 3))]}
	if [[ ! -n ${argv[((${idx} + 3))]} ]]
	then
		print_using
		exit 3
	fi
	cur=
	run_test $v1 $v3 $v2
	echo "Everything is ok !"
	exit 0
fi

# --test2
# 
# Option executes push_swap with checker on 
# sequence from 0 to N numbers, 
# K times on each 'n' between 0..N
# with M as higher bound of random numbers.
#
# In case of 'KO' bad combination will be appended in a file 'fail.txt'
# and execution of script stops.
#
# May be combined with '--print' to get output of every random sequence
# and checker result on it.

if [[ ${cur_sc_opts[(ie)--test2]} -le ${#cur_sc_opts} ]]
then
	v3=${argv[((${idx} + 3))]}
	if [[ ! -n ${argv[((${idx} + 3))]} ]]
	then
		print_using
		exit 3
	fi
	cur=
	v2=$(( v2 + 1 ))
	for ((i = 1; i < $v2; i++))
	do
		run_test $v1 $v3 $i
	done
	echo "Everything is ok !"
	exit 0
fi

# --loop
if [[ ${cur_sc_opts[(ie)--loop]} -le ${#cur_sc_opts} ]]
then
	v3=${argv[((${idx} + 3))]}
	if [[ ! -n ${argv[((${idx} + 3))]} ]]
	then
		print_using
		exit 3
	fi
	cur=
	sum=0
	max=-1
	min=2147483647
	worst_case=()
	v3=${argv[((${idx} + 3))]}
	for ((i = 0; i < $v3; i++))
	do
		nums=()
		gen_rand_numbers $v1 $v2
		cur=$(./push_swap ${nums} | wc -l)
		sum=$(( cur + sum  ))
		if (( max < cur ))
		then
			max=$cur
			worst_case=${nums}
		fi
		if (( min > cur ))
		then
			min=$cur
		fi
	done
	./push_swap ${worst_case} | ./checker -s ${worst_case}
	echo "{${worst_case}}($(( max )))" >> last_combination.txt
	echo Min combinations: $(( min ))
	echo Max combinations: $(( max ))
	echo Avarage: $(( sum / v3 ))
	echo "Worst combination is saved at last_combination.txt"
	exit 0
fi
print_using
