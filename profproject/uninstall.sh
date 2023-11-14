#!/bin/bash

echo "=========================="
echo "Removing App profproject"


LIBPANDA_USER=$(cat /etc/libpanda.d/libpanda_usr)

# Disable the installed services:
echo " - Disabling startup scripts..."
systemctl disable profproject


# Here is where we remove scripts, services, etc.
echo " - Removing scripts..."
cd
if [ "x"`systemctl list-units | grep -c profproject.service` = "x1" ]; then
    echo "Uninstalling profproject.service"

    source /home/$LIBPANDA_USER/catkin_ws/devel/setup.bash
    rosrun robot_upstart uninstall profproject
fi

systemctl daemon-reload # if needed
