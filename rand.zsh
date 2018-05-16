#!/bin/zsh

# Shift
idx=0

ps_opts=("-s" "-c")
sc_opts=("--sequence" "--random" "--print")
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
	exit 1
fi

nums=()
dublicate=()
cur_rand=0

# Generate list of numbers sequence list or random list
if [[ ${cur_sc_opts[(ie)--sequence]} -le ${#cur_sc_opts} ]]
then
	nums=$(echo {${v1}..${v2}})
elif [[ ${cur_sc_opts[(ie)--random]} -le ${#cur_sc_opts} ]]
then
	cnt=$(( $v1 - $v2 ))
	for ((i=0;i<$v2;i++))
	do
		cur_rand="$(( ${RANDOM} % ${v1} ))"
		while [[ ${dublicate[(ie)${cur_rand}]} -le ${#dublicate} ]]
		do
			cur_rand="$(( ${RANDOM} % ${v1} ))"
		done
		nums+="$cur_rand"
		dublicate+="$cur_rand"
	done
fi

if [[ ${cur_sc_opts[(ie)--print]} -le ${#cur_sc_opts} ]]
then
	echo ${nums}
fi

./push_swap ${nums} | ./checker ${(s: :)cur_ps_opts}${nums}
