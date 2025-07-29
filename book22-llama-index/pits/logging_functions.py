from datetime import datetime
import os

from global_settings import LOG_FILE


def log_action(action: str, action_type: str):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    log_entry = f"{timestamp}: {action_type} : {action}\n"
    with open(LOG_FILE, "a") as f:
        f.write(log_entry)


def reset_log():
    with open(LOG_FILE, "w") as f:
        f.truncate(0)
