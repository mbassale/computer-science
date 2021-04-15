package cl.mbassale.hfdp.ch11.protectionProxy;

public class PersonImpl implements Person {

    String name;
    String gender;
    String interests;
    int geekRating;
    int ratingCount = 0;

    @Override
    public String getName() {
        return name;
    }

    @Override
    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String getGender() {
        return gender;
    }

    @Override
    public void setGender(String gender) {
        this.gender = gender;
    }

    @Override
    public String getInterests() {
        return interests;
    }

    @Override
    public void setInterests(String interests) {
        this.interests = interests;
    }

    @Override
    public int getGeekRating() {
        return geekRating;
    }

    @Override
    public void setGeekRating(int geekRating) {
        this.geekRating += geekRating;
        ratingCount++;
    }
}
