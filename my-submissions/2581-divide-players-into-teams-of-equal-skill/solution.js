/**
 * @param {number[]} skill
 * @return {number}
 */
var dividePlayers = function (skill) {
    let n = skill.length;
    let totalTeams = n / 2;
    let teamSkill = 0;
    for (let i = 0; i < skill.length; i++) {
        teamSkill += skill[i];
    }
    if (teamSkill % totalTeams != 0) return -1;
    let eachTeamSkill = teamSkill / totalTeams;
    // sorting the array
    skill.sort((a, b) => {
        return a - b;
    });
    let i = 0;
    n = n - 1;
    let nRes = 0;
    while (i <= n) {
        let chemistry = skill[i] + skill[n];
        if (chemistry == eachTeamSkill) {
            nRes += skill[i] * skill[n];
            i++;
            n--;
        } else {
            return -1;
        }
    }
    return nRes;
};
