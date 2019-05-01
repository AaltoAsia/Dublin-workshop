#!/bin/bash
#
# Testing genaration of O-MI/O-DF write message
#
#
# Create InfoItem with value
function odfInfoItem () {
        echo "<InfoItem name=\"$1\"><value unixTime=\"`date +%s`\">$2</value></InfoItem>"
}

# Create Object with given name and its InfoItems and values
function odfObject () {
        echo "<Object>"
        echo "<id>$1</id>"
        ii_list=$1"_InfoItems"
        set -f
        ii_array=(${!ii_list})
        value_list=$1"_values"
        set -f
        value_array=(${!value_list})
        obj_list=$1"_Object"
        set -f
        obj_array=(${!obj_list})
        for ((ix=0;ix<${#ii_array[*]};ix+=1)); do
                echo "$(odfInfoItem ${ii_array[$ix]} ${value_array[$ix]})"
        done
        for ((ix=0;ix<${#obj_array[*]};ix+=1)); do
                echo "$(odfObject ${obj_array[$ix]})"
        done
        echo "</Object>"
}

# Create Objects from list of Object names (given as argument $1) or from top-level "Objects" variable if no argument
function odfObjects () {
        if [[ -z "$1" ]]
        then o=${Object}
        else o=${1}
        fi
        echo "<Objects xmlns=\"http://www.opengroup.org/xsd/odf/1.0/\">"
        for x in ${o}; do
                echo "$(odfObject ${x})"
        done
        echo "</Objects>"
}

# Create a "write" O-MI message
function omiWrite () {
        echo "<omiEnvelope xmlns=\"http://www.opengroup.org/xsd/omi/1.0/\" version=\"1.0\" ttl=\"0\"><write msgformat=\"odf\"><msg>"
        echo "$(odfObjects)"
        echo "</msg></write></omiEnvelope>"
}
#======================================================================

# Get O-DF tree as variables
while true; do
        source ./create-odf.sh
        echo "$(omiWrite)"
        curl_cmd=$(curl --data "$(omiWrite)" "http://myhost:port")
        echo -e "\n"
        sleep 3
done