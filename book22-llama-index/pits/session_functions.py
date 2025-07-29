import os
import yaml

from global_settings import SESSION_FILE


def load_session(state: dict) -> bool:
    """Load the session state from a file."""
    if os.path.exists(SESSION_FILE):
        with open(SESSION_FILE, "r") as f:
            try:
                loaded_state = yaml.safe_load(f) or {}
                for key, value in loaded_state.items():
                    state[key] = value
                return True
            except yaml.YAMLError as e:
                print(f"Error loading session state: {e}")
                return False
    return False


def save_session(state: dict):
    """Save the current session state to a file."""
    os.makedirs(os.path.dirname(SESSION_FILE), exist_ok=True)
    with open(SESSION_FILE, "w") as f:
        yaml.dump(state, f)
    print(f"Session state saved to {SESSION_FILE}")


def delete_session(state: dict):
    """Delete the session state file."""
    if os.path.exists(SESSION_FILE):
        os.remove(SESSION_FILE)
        for key in list(state.keys()):
            del state[key]
        print(f"Session state file {SESSION_FILE} deleted.")
    else:
        print(f"No session state file found at {SESSION_FILE}.")
