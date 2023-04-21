#!/usr/bin/env bash
dataDir=/var/lib/SSHDMonitor
if [ -d "$dataDir" ]
then
	echo "Test"
else
	mkdir $dataDir
	journalctl -u sshd > $dataDir/TMP_DATA
	grep Accepted $dataDir/TMP_DATA > $dataDir/ACCEPTED
	grep Failed $dataDir/TMP_DATA > $dataDir/FAILED
	rm $dataDir/TMP_DATA
fi
