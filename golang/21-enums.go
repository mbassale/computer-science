package main

import (
	"fmt"
	"math/rand"
	"time"
)

type MailCategory int

const (
	Uncategorized MailCategory = iota
	Personal
	Spam
	Social
	Advertisements
)

func (c MailCategory) String() string {
	switch c {
	case Uncategorized:
		return "Uncategorized"
	case Personal:
		return "Personal"
	case Spam:
		return "Spam"
	case Social:
		return "Social"
	case Advertisements:
		return "Advertisements"
	default:
		return "N/A"
	}
}

type Mail struct {
	category MailCategory
	subject  string
	body     string
}

func (m Mail) String() string {
	return fmt.Sprintf("Category: %v, Subject: %v, Body: %v",
		m.category.String(),
		m.subject,
		m.body)
}

func main() {
	fmt.Printf("Uncategorized: %v\n", Uncategorized)
	fmt.Printf("Personal: %v\n", Personal)
	fmt.Printf("Spam: %v\n", Spam)
	fmt.Printf("Social: %v\n", Social)
	fmt.Printf("Advertisements: %v\n", Advertisements)

	randSource := rand.NewSource(time.Now().Unix())
	randGen := rand.New(randSource)

	numberMails := randGen.Intn(10) + 1
	var mails []Mail
	for i := numberMails; i > 0; i-- {
		randCategory := rand.Intn(int(Advertisements) + 1)
		mails = append(mails, Mail{
			category: MailCategory(randCategory),
			subject:  fmt.Sprintf("Mail #%d", i),
			body:     fmt.Sprintf("Body #%d", i),
		})
	}

	for _, mail := range mails {
		fmt.Println(mail.String())
	}
}
