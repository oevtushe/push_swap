#!/bin/zsh

idx=0
ps_opts=("-s" "-c" "-d")
sc_opts=("--sequence" "--random")
cur_sc_opts=""

# Read options
for name in $argv
do
	if [[ ${ps_opts[(ie)${name}]} -le ${#ps_opts} ]]
	then
		idx=$((idx + 1))
		cur_ps_opts="${cur_ps_opts}${argv[${idx}]} "
	elif [[ ${sc_opts[(ie)${name}]} -le ${#sc_opts} ]]
	then
		idx=$((idx + 1))
		cur_sc_opts="${argv[${idx}]}"
	fi
done

start=${argv[((${idx} + 1))]}
finish=${argv[((${idx} + 2))]}

if [[ ! -n $start ]] && [[ ! -n $finish  ]]
then
	echo "Using: sh test.sh [-scd] <seq start> <seq finish>"
	exit 1
fi

idx=0
typeset -A nums

if [[ ${cur_sc_opts} == ${sc_opts[1]}  ]]
then
	nums=$(echo {${start}..${finish}})
elif [[ ${cur_sc_opts} == ${sc_opts[2]} ]]
then
	cnt=$(( $start - $finish ))
	for ((i=$start;i<$finish;i++))
	do
		nums[$((i - start))]="$(( ${RANDOM} % 1000 ))"
	done
fi

echo ${nums}

echo "./push_swap ${nums} | ./checker ${(s: :)cur_ps_opts}${nums}"
./push_swap ${nums} | ./checker ${(s: :)cur_ps_opts}${nums}
