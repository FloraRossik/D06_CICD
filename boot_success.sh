#!/bin/bash

string="has passed"

curl --data chat_id="833909428" --data-urlencode "text=Pipeline ${string}" https://api.telegram.org/bot5834093397:AAFszuwM8gi0uKbKNQPQzFP1euaKfNkXp1A/sendMessage