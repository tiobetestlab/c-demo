package com.tiobe.ticssql;

import gudusoft.gsqlparser.nodes.TParseTreeNode;

import java.io.File;
import java.util.List;
import java.util.Map;

import com.google.common.collect.Maps;
import com.tiobe.ticssql.parsetree.AstNode;
import com.tiobe.ticssql.rules.Rule;
import com.tiobe.ticssql.rules.Rule.RuleChecker;

public class Analyzer {
    private SqlParser parser;

    public Analyzer(final SqlParser parser) {
        this.parser = parser;
    }
     
    public Map<File, FileResult> analyzeFiles(final List<Rule> rules, final List<File> files) {
        final Map<File, FileResult> result = Maps.newHashMapWithExpectedSize(files.size());
                                                                                           
        for (File file : files) {
            final FileResult fileResult = analyzeFile(rules, file);
                                                                   
            result.put(file, fileResult);
        }
        return result;
    }
     
    public FileResult analyzeFile(final List<Rule> rules, final File file) {
        final FileResult result = new FileResult();
                                                   
        try {
            for (final Rule rule : rules) {
                final RuleChecker checker = rule.createRuleChecker(result);
                                                                           
                for (final AstNode<TParseTreeNode> parseTree : parser.parse(file)) {
                    checker.check(parseTree);
                }
            }
        } catch (final Exception e) {
            result.setError(e);
        }
        return result;
    }
}
