#!/bin/zsh

function gen_rand_numbers {
	dublicate=()
	cur_rand=0
	for ((j = 0; j < $v2; j++))
	do
		cur_rand="$(( ${RANDOM} % ${v1} ))"
		while [[ ${dublicate[(ie)${cur_rand}]} -le ${#dublicate} ]]
		do
			cur_rand="$(( ${RANDOM} % ${v1} ))"
		done
		nums+="$cur_rand"
		dublicate+="$cur_rand"
	done
}

# Shift
idx=0

ps_opts=("-s" "-c")
sc_opts=("--sequence" "--random" "--print" "--save" "--loop")
cur_sc_opts=()
cur_ps_opts=""

# Read options
for name in $argv
do
	if [[ ${ps_opts[(ie)${name}]} -le ${#ps_opts} ]]
	then
		idx=$((idx + 1))
		cur_ps_opts="${cur_ps_opts}${name} "
	elif [[ ${sc_opts[(ie)${name}]} -le ${#sc_opts} ]]
	then
		idx=$((idx + 1))
		cur_sc_opts+="${name}"
	fi
done

v1=${argv[((${idx} + 1))]}
v2=${argv[((${idx} + 2))]}

if ! [[ -n $v1 ]] || ! [[ -n $v2 ]] || ! [[ $v1 == <-> ]] || ! [[ $v2 == <-> ]]
then
	echo "Using: zsh rand.zsh [-scd] [--print] [--sequence <start> <finish>] [--random <max_value> <count>] "
	echo "         [--loop <max_value> <count> <times>]"
	exit 1
fi

nums=()

# Generate list of numbers sequence list or random list
if [[ ${cur_sc_opts[(ie)--sequence]} -le ${#cur_sc_opts} ]]
then
	nums=$(echo {${v1}..${v2}})
elif [[ ${cur_sc_opts[(ie)--random]} -le ${#cur_sc_opts} ]] && ! [[ ${cur_sc_opts[(ie)--loop]} -le ${#cur_sc_opts} ]]
then
	gen_rand_numbers
	if [[ ${cur_sc_opts[(ie)--save]} -le ${#cur_sc_opts} ]]
	then
		echo ${nums} > last_combination.txt
	fi
fi

if [[ ${cur_sc_opts[(ie)--print]} -le ${#cur_sc_opts} ]]
then
	echo ${nums}
fi


if [[ ${cur_sc_opts[(ie)--loop]} -le ${#cur_sc_opts} ]]
then
	cur=
	max=-1
	worst_case=()
	v3=${argv[((${idx} + 3))]}
	for ((i = 0; i < $v3; i++))
	do
		nums=()
		gen_rand_numbers
		cur=$(./push_swap ${nums} | wc -l)
		if (( max < cur ))
		then
			max=$cur
			worst_case=${nums}
		fi
	done
	echo ${worst_case} > last_combination.txt
	./push_swap ${worst_case} | ./checker -s ${worst_case}
else
	./push_swap ${nums} | ./checker ${(s: :)cur_ps_opts}${nums}
fi
