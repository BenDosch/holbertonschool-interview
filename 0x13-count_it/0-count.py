#!/usr/bin/python3
"""Module containing the function count_words that queries the Reddit API,
parses the title of all hot articles, and prints a sorted count of given
keywords."""

import requests


def count_words(subreddit, word_list, after=None):
    """A recursive function that queries the Reddit API, parses the title of
    all hot articles, and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces. Javascript will count as
    javascript, but java will not).

    Args:
        subreddit (str): The name of the subreddit to querry for articles.
        word_list (list[str]): A list keywords that you want to obtain the
            the sorted count for.

    Returns:
        None
    """
    word_list = [x.lower() for x in word_list]
    hot_dict = {x: 0 for x in word_list}
    # Set up url's
    reddit_url = 'https://reddit.com/'
    sub_url = reddit_url + 'r/' + subreddit
    # Set up variables
    headers = {
        'User-agent': 'my_api'
    }
    params = {
        "after": after,
        "limit": 100
    }
    # Start
    subereddit_test = requests.get(sub_url, headers=headers)

    if subereddit_test.status_code is not 200:
        return (None)

    about_json = requests.get(sub_url + "/hot.json",
                              headers=headers,
                              params=params)
    titles = [
        x["data"]["title"] for x in about_json.json()["data"]["children"]
        ]
    for title in titles:
        for word in word_list:
            hot_dict[word] += title.lower().split().count(word)

    checkpoint = about_json.json()['data']['after']

    if checkpoint is not None:
        returned_dict = count_words(subreddit, word_list, checkpoint)
        if returned_dict is not None:
            for word in hot_dict:
                hot_dict[word] += returned_dict[word]
        if after is None:
            sort = sorted(hot_dict.items(), reverse=True, key=lambda x: x[1])
            for v in sort:
                if v[1] == 0:
                    break
                print(v[0] + ": " + str(v[1]))
        return hot_dict

    return None


if __name__ == "__main__":
    count_words("programming", ["react", "python", "java", "javascript",
                                "scala", "no_results_for_this_one"])
