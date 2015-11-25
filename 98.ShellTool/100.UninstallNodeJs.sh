#!/bin/bash

if [ -f /var/db/receipts/org.nodejs.pkg.bom ]; then
  
  lsbom -f -l -s -pf /var/db/receipts/org.nodejs.pkg.bom \
  | while read i; do
    sudo rm /usr/local/${i}
  done
  sudo rm -rf /usr/local/lib/node \
       /usr/local/lib/node_modules \
       /var/db/receipts/org.nodejs.*
 
else
  
  lsbom -f -l -s -pf /var/db/receipts/org.nodejs.node.pkg.bom \
  | while read i; do
    sudo rm /usr/local/${i}
  done
  sudo rm -rf /usr/local/lib/node \
       /usr/local/lib/node_modules \
       /var/db/receipts/org.nodejs.*

fi

exit;


