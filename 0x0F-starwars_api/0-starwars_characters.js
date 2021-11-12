#!/usr/bin/node

const request = require('request');
const myArgs = process.argv.slice(2);
const options = {
  url: 'https://swapi-api.hbtn.io/api/films/' + myArgs[0],
  method: 'GET',
  headers: {
    'Accept-Charset': 'utf-8'
  }
};
request(options, async function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const chars = (JSON.parse(body).characters);
    for (const people of Characters) {
      await new Promise(function (resolve, reject) {
        request(people, function (error, response, body) {
          if (error) reject(error) {
            console.log(error);
          }
          console.log(JSON.parse(body).name);
          resolve();
        });
      });
    }
  }
});
