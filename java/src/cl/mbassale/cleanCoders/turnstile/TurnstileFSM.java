package cl.mbassale.cleanCoders.turnstile;

public abstract class TurnstileFSM {
    private TurnstileState state;

    public void pass() { state.pass(this); }

    public void coin() { state.coin(this); }

    public void setState(TurnstileState state) { this.state = state; }

    public abstract void alarm();

    public abstract void lock();

    public abstract void unlock();

    public abstract void thankYou();

}
