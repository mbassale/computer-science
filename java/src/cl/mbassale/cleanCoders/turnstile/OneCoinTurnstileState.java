package cl.mbassale.cleanCoders.turnstile;

public enum OneCoinTurnstileState implements TurnstileState {
    LOCKED {
        @Override
        public void pass(TurnstileFSM fsm) {
            fsm.alarm();
        }

        @Override
        public void coin(TurnstileFSM fsm) {
            fsm.setState(UNLOCKED);
            fsm.unlock();
        }
    },

    UNLOCKED {
        @Override
        public void pass(TurnstileFSM fsm) {
            fsm.setState(LOCKED);
            fsm.lock();
        }

        @Override
        public void coin(TurnstileFSM fsm) {
            fsm.thankYou();
        }
    }
}
