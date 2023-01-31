# Contributing

## Pull Request (PR) Workflow

0. Read the [pull request merge checklist](#pull-request-merge-checklist) and
   plan your work around it.
1. Find an issue to work on and assign yourself to it. If an issue does not
   exist for what you want to work on, create the issue first.
2. Push your (unfinished) work early so others can see it. You need to create a
   branch with the prefix `f/` for feature, `h/` for (hot)fix, `d/` for
   documentation, or `r/` for refactor. E.g. `f/add-lic-5` for a PR that adds
   the 5th LIC function to the program.
3. Right away, open a PR on GitHub based on that branch. Assign yourself to the
   PR, and add a "draft" label to the PR if you don't think it's ready to be
   merged. Insert [the below checklist](#pull-request-merge-checklist) as the
   first comment on your PR. The title and description of the PR will be used
   for the final merge commit title and body, respectively. These can edited
   while developing your PR. [Link your pull
   request](https://docs.github.com/en/issues/tracking-your-work-with-issues/linking-a-pull-request-to-an-issue)
   to the issue(s) that it will resolve.
4. If you think the PR is ready to be merged and have handled all checklist
   items, remove the "draft" label (if present) and ask for a review. The PR
   reviewer(s) should double check that all checklist items are taken care of
   before merging the PR. Failing to follow the checklist could lead to not
   meeting our project requirements.

## Pull Request Merge Checklist

```
- [ ] Feature/fix PRs should add one atomic (as small as possible) feature or
  fix
- [ ] If your PR adds a feature or fix it also needs to add or modify at least
  one test
- [ ] All code in your PR needs to have been formatted by `clang-format`
- [ ] The merge commit title should follow our commit prefix convention of
  either "feat", "fix", "doc", or "refactor"
- [ ] The merge commit body should reference at least one issue
- [ ] The code compiles and all the tests pass
```


## GitHub Setup

All PRs use squash merges. There is an automatic block against merging PRs that
haven't been approved by at least one other person, and so the author should
request a reviewer when they deem the PR ready for merging.
