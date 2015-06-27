NAME=$1
DATA="scripts/data"
DEST="src/Makefile.am"

cp src/example.c src/${NAME}.c &&
sed -i "s/example/${NAME}/g" src/${NAME}.c &&
echo "${NAME}" >> ${DATA}/list.txt &&
cat ${DATA}/list.txt | sort > ${DATA}/list.txt.temp &&
mv ${DATA}/list.txt.temp ${DATA}/list.txt &&
echo -e "AM_CFLAGS =\nAM_LDFLAGS =\nbin_PROGRAMS =" > ${DEST} &&
while read line; do
	echo -e "\nbin_PROGRAMS += ${line}\n${line}_SOURCES = ${line}.c" >> ${DEST}
done <${DATA}/list.txt
