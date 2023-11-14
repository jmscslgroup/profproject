#!/bin/bash

echo "=========================="
echo "Starting App profproject for {APP_NAME_PRETTY}"


systemctl start profproject
systemctl start rosnodeChecker
